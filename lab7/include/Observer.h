#pragma once
#include <list>
#include <memory>
#include <mutex>

template<class Event>
class Observable;

template<class Event>
class IObserver
{
public:
    virtual void notify (Event event) = 0;
};

template<class Event>
class Observable
{
private:
    std::mutex mtxO;
    std::list<std::shared_ptr<IObserver<Event>>> subscibers;
public:
    void notifySubs(Event event){
        std::lock_guard<std::mutex> lock(mtxO);
        for (const auto &sub : subscibers) sub->notify(event);
    }
    void subscribe (std::shared_ptr<IObserver<Event>> subscriber){
        std::lock_guard<std::mutex> lock(mtxO);
         subscibers.push_back(subscriber);
}  
};
