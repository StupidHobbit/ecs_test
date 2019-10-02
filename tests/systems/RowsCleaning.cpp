#include "base.h"


class RowsCleaningSystemTest : public SystemsTest {
protected:
    int last_row;
    virtual void SetUp() {
        gm.add_system<RowsCleaningSystem>();
        last_row = get_field_size().first - 1;
    }
    void fill_last_row(){
        for (int i = 0; i < get_field_size().second; i++){
            auto entity = gm.registry.create();
            gm.registry.assign<Block>(entity, last_row, i);
        }
    }
};

TEST_F(RowsCleaningSystemTest, step_forward_delete_row) {
fill_last_row();
make_n_steps(1);
auto table = get_table_from(gm.registry);
ASSERT_EQ(count_blocks(table), 4);
}

TEST_F(RowsCleaningSystemTest, step_forward_block_falls) {
fill_last_row();
auto &block = gm.registry.assign<Block>(entity1, last_row - 1, 0);
make_n_steps(1);
ASSERT_EQ(block.row, last_row);
}