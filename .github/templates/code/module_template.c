/**
 * @file    <module_name>.c
 * @brief   Implementation of <short description of module>.
 */

#include "<module_name>.h"

/*==================[ LOCAL DEFINES ]======================================*/

/* Example internal limits (if needed) */
#define <MODULE_NAME>_MIN_VALUE   ((uint16_t)0U)

/*==================[ LOCAL FUNCTIONS ]====================================*/

static bool <ModuleName>_IsConfigValid(const <ModuleName>_ConfigType * config);

/*==================[ GLOBAL FUNCTIONS ]===================================*/

<ModuleName>_ErrorType <ModuleName>_Init(
    const <ModuleName>_ConfigType * config,
    <ModuleName>_StateType * state)
{
    <ModuleName>_ErrorType ret = <MODULE_NAME>_E_OK;

    if ((config == (const <ModuleName>_ConfigType *)0) ||
        (state == ( <ModuleName>_StateType *)0))
    {
        ret = <MODULE_NAME>_E_PARAM;
    }
    else if (!<ModuleName>_IsConfigValid(config))
    {
        ret = <MODULE_NAME>_E_PARAM;
    }
    else
    {
        state->current_value = config->initial_value;
        state->is_initialized = true;
    }

    return ret;
}

<ModuleName>_ErrorType <ModuleName>_Deinit(<ModuleName>_StateType * state)
{
    <ModuleName>_ErrorType ret = <MODULE_NAME>_E_OK;

    if (state == ( <ModuleName>_StateType *)0)
    {
        ret = <MODULE_NAME>_E_PARAM;
    }
    else
    {
        state->current_value = (uint16_t)0;
        state->is_initialized = false;
    }

    return ret;
}

<ModuleName>_ErrorType <ModuleName>_Process(
    <ModuleName>_StateType * state,
    uint16_t input)
{
    <ModuleName>_ErrorType ret = <MODULE_NAME>_E_OK;

    if ((state == ( <ModuleName>_StateType *)0) ||
        (state->is_initialized == false))
    {
        ret = <MODULE_NAME>_E_NOT_INIT;
    }
    else
    {
        /* Example processing: simple saturation */
        uint32_t temp = (uint32_t)state->current_value + (uint32_t)input;

        if (temp > (uint32_t)UINT16_MAX)
        {
            state->current_value = UINT16_MAX;
        }
        else
        {
            state->current_value = (uint16_t)temp;
        }
    }

    return ret;
}

<ModuleName>_ErrorType <ModuleName>_GetOutput(
    const <ModuleName>_StateType * state,
    uint16_t * output)
{
    <ModuleName>_ErrorType ret = <MODULE_NAME>_E_OK;

    if ((state == (const <ModuleName>_StateType *)0) ||
        (output == (uint16_t *)0))
    {
        ret = <MODULE_NAME>_E_PARAM;
    }
    else if (state->is_initialized == false)
    {
        ret = <MODULE_NAME>_E_NOT_INIT;
    }
    else
    {
        *output = state->current_value;
    }

    return ret;
}

/*==================[ LOCAL FUNCTIONS ]====================================*/

static bool <ModuleName>_IsConfigValid(const <ModuleName>_ConfigType * config)
{
    bool is_valid = false;

    if ((config->max_value >= config->initial_value) &&
        (config->max_value > <MODULE_NAME>_MIN_VALUE))
    {
        is_valid = true;
    }
    else
    {
        /* leave as false */
    }

    return is_valid;
}
