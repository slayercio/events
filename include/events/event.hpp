#pragma once
#include <events/event_handler.hpp>
#include <events/mem.hpp>
#include <deque>

namespace event
{
    template<typename PayloadType>
    class Event
    {
    public:
        using Handler = EventHandler<PayloadType>;
     
        Event& operator+=(Handler handler);
        Event& operator-=(Handler handler);

        void operator()(event::Ref<PayloadType> payload);

        void Invoke(event::Ref<PayloadType> payload);

    private:
        std::deque<Handler> _Handlers;
    };
}

namespace event {
    template<typename PT>
    inline Event<PT>& Event<PT>::operator+=(Event<PT>::Handler handler)
    {
        _Handlers.push_back(handler);

        return *this;
    }

    template<typename PT>
    inline Event<PT>& Event<PT>::operator-=(Event<PT>::Handler handler)
    {
        auto it = std::find(_Handlers.begin(), _Handlers.end(), handler);

        if(it != _Handlers.end()) _Handlers.erase(it);
        return *this;
    }

    template<typename PT>
    inline void Event<PT>::operator()(event::Ref<PT> payload)
    {
        this->Invoke(payload);
    }

    template<typename PT>
    inline void Event<PT>::Invoke(event::Ref<PT> payload) 
    {
        for(const Handler& handler: _Handlers)
            handler(payload);
    }
}