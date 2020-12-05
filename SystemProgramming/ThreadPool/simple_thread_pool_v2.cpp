



//=============================================<Siurce Code(S)>=============================================

#include <bits/stdc++.h>
//#include <functional>
//#include <iostream>
using namespace std;

//---------------------------------------------
class join_threads
{
	private:
		std::vector<std::thread>& threads;
		//std::vector<std::thread> threads; // This Will not work
	public:
		//explicit join_threads(std::vector<std::thread>& threads_): threads(threads_) {}
		join_threads(std::vector<std::thread>& threads_): threads(threads_) {}
		~join_threads()
		{
			for(unsigned long i=0;i<threads.size();++i)
			{
				if(threads[i].joinable())
					threads[i].join();
			}
		}
};

//---------------------------------------------
// thread-safe queue
template<typename T>
class threadsafe_queue
{
	private:
		mutable std::mutex mut;
		std::queue<T> data_queue;
		std::condition_variable data_cond;
	public:
		threadsafe_queue() {}

		void push(T new_value)
		{
			std::lock_guard<std::mutex> lk(mut);
			data_queue.push(std::move(new_value));
			data_cond.notify_one();
		}

		void wait_and_pop(T& value)
		{
			std::unique_lock<std::mutex> lk(mut);
			data_cond.wait(lk, [this]{return !data_queue.empty();});
			value=std::move(data_queue.front());
			data_queue.pop();
		}

		std::shared_ptr<T> wait_and_pop()
		{
			std::unique_lock<std::mutex> lk(mut);
			data_cond.wait(lk, [this]{return !data_queue.empty();});
			std::shared_ptr<T> res(std::make_shared<T>(std::move(data_queue.front())));
			data_queue.pop();
			return res;
		}

		bool try_pop(T& value)
		{
			std::lock_guard<std::mutex> lk(mut);
			if(data_queue.empty())
				return false;
			value = std::move(data_queue.front());
			data_queue.pop();
			return true;
		}

		std::shared_ptr<T> try_pop()
		{
			std::lock_guard<std::mutex> lk(mut);
			if(data_queue.empty())
				return std::shared_ptr<T>();
			std::shared_ptr<T> res(std::make_shared<T>(std::move(data_queue.front())));
			data_queue.pop();
			return res;
		}

		bool empty() const 
		{
			std::lock_guard<std::mutex> lk(mut);
			return data_queue.empty();
		}
};

//---------------------------------------------
// The simplest possible thread pool

class thread_pool {
	std::atomic_bool done;
	threadsafe_queue<std::function<void(int)>> work_queue;
	std::vector<std::thread> threads;
	join_threads joiner;
	void worker_thread() {
		//std::thread::id my_thread_id = std::this_thread::get_id();
		//std::cout << "my_thread_id: " << my_thread_id << "\n";
		while(!done)
		{
			std::function<void(int)> task;
			if(work_queue.try_pop(task))
			{
				task(123);
			}
			else
			{
				std::this_thread::yield();
			}
		}
	}
	public:
	thread_pool(): done(false), joiner(threads)
	{
		unsigned const thread_count = std::thread::hardware_concurrency();
		try
		{
			cout << "Thread Create Count: " << thread_count << endl;
			for(unsigned i=0; i<thread_count; ++i)
			{
				threads.push_back(std::thread(&thread_pool::worker_thread, this));
			}
		}
		catch(...)
		{
			done = true;
			//throw;
		}
	}
	~thread_pool()
	{
		done = true;
	}

	template<typename FunctionType>
		void submit(FunctionType f)
		{
			work_queue.push(std::function<void(int)>(f));
		}
};

//---------------------------------------------

void print_nums_100(int i)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(10));
	std::cout << i << endl;
}

void print_nums_200(int i)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(1));
	std::cout << i << endl;
}

int main()
{
	thread_pool pool;

	std::function<void(int)> f_display_100 = print_nums_100;
	std::function<void(int)> f_display_200 = print_nums_200;
	pool.submit(f_display_100);
	pool.submit(f_display_200);
	//std::this_thread::sleep_for(std::chrono::milliseconds(10000));
	pool.submit(f_display_100);
	//std::this_thread::sleep_for(std::chrono::milliseconds(10000));
	pool.submit(f_display_100);
	//std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	return 0;
}

//=============================================<Siurce Code(E)>=============================================


