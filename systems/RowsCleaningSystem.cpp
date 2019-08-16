#include "RowsCleaningSystem.h"
#include "utils.h"
#include "../utils/getters.h"

void RowsCleaningSystem::step_forward(int elapsed) {
    auto table = get_table_from(registry);
    auto last_row = get_field_size().first - 1;
    if (std::any_of(table[last_row].begin(), table[last_row].end(), [](auto x){return !x;}))
        return;
    registry.view<Block>().each([this, last_row](auto entity, auto &block) {
        if (block.row == last_row)
            registry.destroy(entity);
        else
            block.row++;
    });
}

void RowsCleaningSystem::step_back(int elapsed) {

}

RowsCleaningSystem::RowsCleaningSystem(entt::registry *registry) : System(registry) {

}
