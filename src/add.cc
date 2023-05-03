#include <node_api.h>

napi_value Add(napi_env env, napi_callback_info info)
{
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    int first, second;
    napi_get_value_int32(env, args[0], &first);
    napi_get_value_int32(env, args[1], &second);
    napi_value result;
    napi_create_int32(env, first + second, &result);
    return result;
}

napi_value Init(napi_env env, napi_value exports)
{
    napi_status status;
    napi_value fn;
    status = napi_create_function(env, "add", NAPI_AUTO_LENGTH, Add, nullptr, &fn);
    if (status != napi_ok)
    {
        napi_throw_error(env, nullptr, "Failed to create function");
    }
    status = napi_set_named_property(env, exports, "add", fn);
    if (status != napi_ok)
    {
        napi_throw_error(env, nullptr, "Failed to set exports");
    }
    return exports;
}

NAPI_MODULE(addon, Init)