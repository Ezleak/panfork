ninja -C "build-android" install
cp /home/electimon/panfork_offscreen_rootless/build-android/src/gallium/targets/osmesa/libOSMesa.so.8.0.0 ~/PojavLauncher/app_pojavlauncher/src/main/jniLibs/arm64-v8a/libOSMesa_pan.so
cd -
./gradlew :app_pojavlauncher:assembleDebug
cp ./app_pojavlauncher/build/outputs/apk/debug/app_pojavlauncher-debug.apk ~/android-ndk-r25c/toolchains/llvm/prebuilt/linux-x86_64/bin/
