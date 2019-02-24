#include <node.h>
#include <node_buffer.h>
#include <v8.h>
#include <stdint.h>
#include <nan.h>

extern "C" {
    #include "cryptonight.h"
    #include "cryptonight_light.h"
}

#define THROW_ERROR_EXCEPTION(x) Nan::ThrowError(x)

void callback(char* data, void* hint) {
  free(data);
}

using namespace node;
using namespace v8;
using namespace Nan;

NAN_METHOD(cryptonight) {

        uint32_t cn_variant = 0;
        uint64_t height = 0;

        if (info.Length() < 2)
        return THROW_ERROR_EXCEPTION("You must provide two arguments.");

        if (info.Length() >= 2) {
            if (info[1]->IsUint32())
                cn_variant = info[1]->ToUint32()->Uint32Value();
            else
                return THROW_ERROR_EXCEPTION("Argument 2 should be an int32");
        }

        if (info.Length() >= 3) {
            if (info[2]->IsNumber())
                height = info[2]->ToUint32()->Uint32Value();
            else
                return THROW_ERROR_EXCEPTION("Argument 3 should be a number");
        }

        Local<Object> target = info[0]->ToObject();

        if (!Buffer::HasInstance(target))
        return THROW_ERROR_EXCEPTION("Argument should be a buffer object.");

        char * input = Buffer::Data(target);
        char output[32];

        uint32_t input_len = Buffer::Length(target);

        if (cn_variant > 0 && input_len < 43)
            return THROW_ERROR_EXCEPTION("Argument must be 43 bytes for cryptonight variant 1+");

	if (cn_variant >= 4 && height == 0)
            return THROW_ERROR_EXCEPTION("Height must be provided for cryptonightR (variant 4+)");

        cn_slow_hash(input, input_len, output, cn_variant, 0, height);

        v8::Local<v8::Value> returnValue = Nan::CopyBuffer(output, 32).ToLocalChecked();
        info.GetReturnValue().Set(
        returnValue
        );
}

NAN_METHOD(cryptonight_light) {

        uint32_t light = 1;
        uint32_t cn_variant = 0;

        if (info.Length() < 2)
        return THROW_ERROR_EXCEPTION("You must provide two arguments.");

        if (info.Length() >= 2) {
            if (info[1]->IsUint32())
                light = info[1]->ToUint32()->Uint32Value();
            else
                return THROW_ERROR_EXCEPTION("Argument 2 should be an int32");
            if (info[2]->IsUint32())
                cn_variant = info[2]->ToUint32()->Uint32Value();
            else
                return THROW_ERROR_EXCEPTION("Argument 3 should be an int32");
        }

        Local<Object> target = info[0]->ToObject();

        if (!Buffer::HasInstance(target))
        return THROW_ERROR_EXCEPTION("Argument should be a buffer object.");

        char * input = Buffer::Data(target);
        char output[32];

        uint32_t input_len = Buffer::Length(target);

        if (cn_variant > 0 && input_len < 43)
            return THROW_ERROR_EXCEPTION("Argument must be 43 bytes for cryptonight light variant 1+");
        cn_light_slow_hash(input, input_len, output, light, cn_variant);

        v8::Local<v8::Value> returnValue = Nan::CopyBuffer(output, 32).ToLocalChecked();
        info.GetReturnValue().Set(
        returnValue
        );
}

NAN_MODULE_INIT(init) {
    Nan::Set(target, Nan::New("cryptonight").ToLocalChecked(), Nan::GetFunction(Nan::New<FunctionTemplate>(cryptonight)).ToLocalChecked());
    Nan::Set(target, Nan::New("cryptonight_light").ToLocalChecked(), Nan::GetFunction(Nan::New<FunctionTemplate>(cryptonight_light)).ToLocalChecked());
}

NODE_MODULE(cryptonighthashing, init)
