#include "base.h"

uint64_t hash(entt::registry &registry) {
    uint64_t registry_hash = 0;
    registry.each([&registry_hash, &registry](entt::entity entity){
        registry_hash += hash(entity, registry);
    });
    return registry_hash;
}

uint64_t hash(entt::entity entity, entt::registry &registry){
    return get_component_hash<Figure>(entity, registry);
}

template <class T>
uint64_t get_component_hash(entt::entity entity, entt::registry &registry){
    auto componentp = registry.try_get<T>(entity);
    return componentp == nullptr ? 0 : hash(*componentp);
}

uint64_t hash(Figure figure) {
    return
            ((((((static_cast<uint64_t>(figure.is_valid << 2) + figure.current_state << 5) +
                figure.center.row << 5) + figure.center.column << 14) +
              figure.shift.y << 14) + figure.shift.y << 8) + figure.pattern->name[0] << 9) + figure.speed;
}
