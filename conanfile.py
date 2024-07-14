from conan import ConanFile
from conan.tools.cmake import CMake, CMakeToolchain, CMakeDeps, cmake_layout

class BasicConanfile(ConanFile):
    name = "pkg"
    version = "1.0"
    description = "A basic recipe"
    license = "<Your project license goes here>"
    homepage = "<Your project homepage goes here>"

    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeToolchain", "CMakeDeps"
    
    def layout(self):
        cmake_layout(self)

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()
