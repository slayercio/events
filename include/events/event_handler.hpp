#pragma once
#include <functional>
#include <events/mem.hpp>

template <typename PayloadType>
using EventHandler = std::function<void(event::Ref<T>)>;