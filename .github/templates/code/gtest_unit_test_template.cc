#include "gtest/gtest.h"

extern "C"
{
#include "<module_name>.h"
}

/**
 * @brief   Test fixture for <ModuleName>.
 */
class <ModuleName>Test : public ::testing::Test
{
protected:
    <ModuleName>_ConfigType config{};
    <ModuleName>_StateType  state{};

    void SetUp() override
    {
        config.initial_value    = 0u;
        config.max_value        = 100u;
        config.enable_feature_x = false;

        (void)<ModuleName>_Init(&config, &state);
    }

    void TearDown() override
    {
        (void)<ModuleName>_Deinit(&state);
    }
};

// GIVEN: Initialized module
// WHEN:  Processing a small input
// THEN:  Output increases accordingly and stays within range
TEST_F(<ModuleName>Test,
       GIVEN_InitializedModule_WHEN_ProcessSmallInput_THEN_OutputUpdatedWithinRange)
{
    // GIVEN
    uint16_t output = 0u;

    // WHEN
    <ModuleName>_ErrorType err = <ModuleName>_Process(&state, 10u);

    // THEN
    EXPECT_EQ(err, <MODULE_NAME>_E_OK);
    err = <ModuleName>_GetOutput(&state, &output);
    EXPECT_EQ(err, <MODULE_NAME>_E_OK);
    EXPECT_EQ(output, 10u);
}

// GIVEN: Module not initialized
// WHEN:  Process is called
// THEN:  NOT_INIT error is reported
TEST(<ModuleName>StandaloneTest,
     GIVEN_NotInitialized_WHEN_ProcessCalled_THEN_ErrorReported)
{
    <ModuleName>_StateType  local_state{};
    <ModuleName>_ErrorType  err;

    err = <ModuleName>_Process(&local_state, 5u);

    EXPECT_EQ(err, <MODULE_NAME>_E_NOT_INIT);
}
