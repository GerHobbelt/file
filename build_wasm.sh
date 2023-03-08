# Run emmake with the normal make to generate wasm object files.
emmake make FILE_COMPILE=../native/file

emcc src/.libs/libmagic.so -o wasm/libmagic.js --preload-file magic/magic.mgc -s ALLOW_MEMORY_GROWTH -s EXPORTED_FUNCTIONS=_magic_open,_magic_close,_magic_error,_magic_errno,_magic_descriptor,_magic_buffer,_magic_getflags,_magic_setflags,_magic_check,_magic_compile,_magic_list,_magic_load,_magic_load_buffers,_magic_setparam,_magic_getparam,_magic_version,_magic_wrapper

