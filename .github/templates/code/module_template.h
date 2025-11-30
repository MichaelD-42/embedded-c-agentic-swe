#ifndef <MODULE_NAME>_H_
#define <MODULE_NAME>_H_

/**
 * @file    <module_name>.h
 * @brief   Interface for <short description of module>.
 *
 * @details
 *   - Automotive embedded C19
 *   - No dynamic memory allocation
 *   - MISRA-style interfaces
 */

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/*==================[ DEFINES ]============================================*/

/* Module-specific error codes (example) */
typedef enum
{
    <MODULE_NAME>_E_OK = 0,
    <MODULE_NAME>_E_NOT_INIT,
    <MODULE_NAME>_E_PARAM,
    <MODULE_NAME>_E_INTERNAL
} <ModuleName>_ErrorType;

/*==================[ TYPEDEFS ]===========================================*/

/** Configuration structure for <ModuleName>. */
typedef struct
{
    uint16_t initial_value;
    uint16_t max_value;
    bool     enable_feature_x;
} <ModuleName>_ConfigType;

/** Runtime data for <ModuleName>. */
typedef struct
{
    uint16_t current_value;
    bool     is_initialized;
} <ModuleName>_StateType;

/*==================[ API ]================================================*/

/**
 * @brief   Initialize the module.
 *
 * @param[in]  config   Pointer to configuration (shall not be NULL).
 * @param[out] state    Pointer to state object (shall not be NULL).
 *
 * @return <MODULE_NAME>_E_OK if initialization was successful.
 */
<ModuleName>_ErrorType <ModuleName>_Init(
    const <ModuleName>_ConfigType * config,
    <ModuleName>_StateType * state);

/**
 * @brief   Deinitialize the module.
 *
 * @param[in,out] state Pointer to state object.
 *
 * @return <MODULE_NAME>_E_OK if deinitialization was successful.
 */
<ModuleName>_ErrorType <ModuleName>_Deinit(<ModuleName>_StateType * state);

/**
 * @brief   Process one cycle / step.
 *
 * @param[in,out] state   Pointer to state object.
 * @param[in]     input   Input value.
 *
 * @return <MODULE_NAME>_E_OK if processing was successful.
 */
<ModuleName>_ErrorType <ModuleName>_Process(
    <ModuleName>_StateType * state,
    uint16_t input);

/**
 * @brief   Get the current output value.
 *
 * @param[in]  state   Pointer to state object.
 * @param[out] output  Pointer to output value.
 *
 * @return <MODULE_NAME>_E_OK if output is valid.
 */
<ModuleName>_ErrorType <ModuleName>_GetOutput(
    const <ModuleName>_StateType * state,
    uint16_t * output);

#ifdef __cplusplus
}
#endif

#endif /* <MODULE_NAME>_H_ */
