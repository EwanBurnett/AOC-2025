include(FetchContent)

FetchContent_Declare(
	gtest
	GIT_REPOSITORY https://github.com/google/googletest
	GIT_TAG v1.17.0
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(gtest)

add_subdirectory(01)