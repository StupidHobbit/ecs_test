#include "gtest/gtest.h"

#include "../Systems.h"
#include "../Components.h"

using testing::Eq;

TEST(System, has_step_forward){
    &System::step_forward;
}

TEST(System, has_step_back){
    &System::step_back;
}

class SystemsTest : public testing::Test{
public:
    entt::registry registry;

};

TEST_F(SystemsTest, FiguresSpawnerSystem_step_forward){
    FiguresSpawnerSystem system(&registry);
    ASSERT_EQ(registry.view<Figure>().size(), 0);
    system.step_forward(16);
    ASSERT_EQ(registry.view<Figure>().size(), 1);
}