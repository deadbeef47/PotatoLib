#pragma once

#include <memory>

template<typename T>
class Singleton {
public:
	static std::shared_ptr<T> GetInstance() {
		if (mInstance == nullptr) {
			mInstance = std::make_shared<T>();
		}
		return mInstance;
	}

private:
	//Singleton(const Singleton&) = delete;
    //Singleton& operator=(const Singleton&) = delete;
    //Singleton(Singleton&&) = delete;
    //Singleton& operator=(Singleton&&) = delete;

private:
	static std::shared_ptr<T> mInstance;
};

template<typename T>
std::shared_ptr<T> Singleton<T>::mInstance = nullptr;
