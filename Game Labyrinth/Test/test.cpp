#include <iostream>
#include <Windows.h>
#include "game.h"

void set_color(int text_color, int bg_color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (bg_color << 4) | text_color);
}

namespace TestSystem {
    int count_success = 0, count_failed = 0;

    void start_test(bool(*test)(), const char* name_of_test) {
        set_color(2, 0);
        std::cout << "[ RUN      ]";
        set_color(7, 0);
        std::cout << name_of_test << std::endl;

        bool status = test();

        if (status == true) {
            set_color(2, 0);
            std::cout << "[       OK ]" << std::endl;
            count_success++;
        }
        else {
            set_color(4, 0);
            std::cout << "[  FAILED  ]" << std::endl;
            count_failed++;
        }
        set_color(7, 0);
    }

    template <class T>
    bool check(const T& expected, const T& actual) {
        if (expected == actual) {
            return true;
        }
        else {
            std::cerr << "Expected result is " << expected <<
                ", but actual is " << actual << "." << std::endl;
            return false;
        }
    }

    template <class T>
    bool check_not_equal(const T& expected, const T& actual) {
        if (expected == actual) {
            std::cerr << "Expected result and actual result" <<
                "are equal." << std::endl;
            return false;
        }
        else {
            return true;
        }
    }

    void print_init_info() {
        set_color(2, 0);
        std::cout << "[==========] " << std::endl;
        set_color(7, 0);
    }

    void print_final_info() {
        set_color(2, 0);
        std::cout << "[==========] ";
        set_color(7, 0);
        std::cout << count_success + count_failed << " test" <<
            (count_success + count_failed > 1 ? "s" : "") <<
            " ran." << std::endl;
        set_color(2, 0);
        std::cout << "[  PASSED  ] ";
        set_color(7, 0);
        std::cout << count_success << " test" <<
            (count_success > 1 ? "s" : "") << std::endl;
        if (count_failed > 0) {
            set_color(4, 0);
            std::cout << "[  FAILED  ] ";
            set_color(7, 0);
            std::cout << count_failed << " test" <<
                (count_failed > 1 ? "s." : ".") << std::endl;
        }
    }
};

bool test1_try_create_default_game_object() {
    GameObject object;
    return true;
}

bool test2_try_create_object() {
    GameObject object(5, 5, false);
    return true;
}

bool test3_try_copy_object() {
    bool expected_result = true;
    bool actual_result = false;

    try {
        GameObject object1(5, 5, false), object2(object1);
        actual_result = true;
    }
    catch (std::exception& ex) {
        actual_result = false;
    }

    return TestSystem::check(expected_result, actual_result);
}

bool test4_try_create_default_character() {
    Character character;
    return true;
}

bool test5_try_create_character() {
    Character character(5, 5);
    return true;
}

bool test6_try_copy_character() {
    bool expected_result = true;
    bool actual_result = false;

    try {
        Character character1(5, 5), character2(character1);
        actual_result = true;
    }
    catch (std::exception& ex) {
        actual_result = false;
    }

    return TestSystem::check(expected_result, actual_result);
}

bool test7_try_create_default_teleport() {
    Teleport teleport;
    return true;
}

bool test8_try_create_teleport() {
    Teleport teleport(5, 5, 10, 7);
    return true;
}

bool test9_try_copy_teleport() {
    bool expected_result = true;
    bool actual_result = false;

    try {
        Teleport teleport1(5, 5, 10, 7), teleport2(teleport1);
        actual_result = true;
    }
    catch (std::exception& ex) {
        actual_result = false;
    }

    return TestSystem::check(expected_result, actual_result);
}

bool test10_try_create_default_wall() {
    Wall wall;
    return true;
}

bool test11_try_create_wall() {
    Wall wall(5, 5);
    return true;
}

bool test12_try_copy_wall() {
    bool expected_result = true;
    bool actual_result = false;

    try {
        Wall wall1(5, 5), wall2(wall1);
        actual_result = true;
    }
    catch (std::exception& ex) {
        actual_result = false;
    }

    return TestSystem::check(expected_result, actual_result);
}

int main() {
    TestSystem::start_test(test1_try_create_default_game_object, "GameObject.test1_try_create_default_game_object");
    TestSystem::start_test(test2_try_create_object, "GameObject.test2_try_create_object");
    TestSystem::start_test(test3_try_copy_object, "GameObject.test3_try_copy_object");
    TestSystem::start_test(test4_try_create_default_character, "Character.test4_try_create_default_character");
    TestSystem::start_test(test5_try_create_character, "Character.test5_try_create_character");
    TestSystem::start_test(test6_try_copy_character, "Character.test6_try_copy_character");
    TestSystem::start_test(test7_try_create_default_teleport, "Teleport.test7_try_create_default_teleport");
    TestSystem::start_test(test8_try_create_teleport, "Teleport.test8_try_create_teleport");
    TestSystem::start_test(test9_try_copy_teleport, "Teleport.test9_try_copy_teleport");
    TestSystem::start_test(test10_try_create_default_wall, "Wall.test10_try_create_default_wall");
    TestSystem::start_test(test11_try_create_wall, "Wall.test11_try_create_wall");
    TestSystem::start_test(test12_try_copy_wall, "Wall.test12_try_copy_wall");
    return 0;
}