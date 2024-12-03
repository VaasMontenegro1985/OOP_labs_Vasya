#pragma once
#include <list>
#include <memory>

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
    std::list<std::shared_ptr<IObserver<Event>>> subscibers;
public:
    void notifySubs(Event event){
        for (const auto &sub : subscibers) sub->notify(event);
    }
    void subscribe (std::shared_ptr<IObserver<Event>> subscriber){
         subscibers.push_back(subscriber);
}  
};
