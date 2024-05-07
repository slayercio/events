#pragma once
#include <memory>

namespace event {
    template<typename Type>
    using Ref = std::shared_ptr<Type>;

    template<typename Type, typename... Args>
    constexpr Ref<Type> CreateRef(Args&& ...args) 
    {
        return std::make_shared<Type>(std::forward<Args>(args)...);
    }

    template<typename Type>
    using Ptr = std::unique_ptr<Type>;

    template<typename Type, typename... Args>
    constexpr Ptr<Type> CreatePtr(Args&& ...args)
    {
        return std::make_unique<Type>(std::forward<Args>(args)...);
    }
}