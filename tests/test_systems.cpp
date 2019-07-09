#include "gtest/gtest.h"

#include "../Systems.h"

using testing::Eq;

TEST(System, has_step_forward){
    &System::step_forward;
}

TEST(System, has_step_back){
    &System::step_back;
}