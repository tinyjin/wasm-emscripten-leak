project('test',
        'cpp',
        default_options : ['buildtype=debugoptimized', 'b_sanitize=none', 'werror=false', 'optimization=s', 'cpp_std=c++14', 'strip=true'],
        version : '0.0.1',
        license : 'MIT')

cc = meson.get_compiler('cpp')

if (cc.get_id() == 'emscripten')
    source_file = files('test.cpp')
    test_wasm_dep = declare_dependency(include_directories
                                         : include_directories('.'), sources
                                         : source_file)
    executable('test-wasm',
        [],
        dependencies : [test_wasm_dep],
        )

else
    message('wasm compiler is not the emscripten!')
endif
