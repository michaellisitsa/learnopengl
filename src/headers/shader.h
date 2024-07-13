#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader
{
public:
    unsigned int ID;

    Shader(const char *vertexPath, const char *fragmentPath)
    {
        std::string vectorCode;
        std::string fragmentCode;
        std::ifstream vShaderFile;
        std::ifstream fShaderFile;
        std::string path = "../shaders/";
        // Unlike Javascript, file reading does not cause an exception in C++.
        // We can explicitly throw an exception using an exception mask.
        vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        try
        {
            // The path here is read from the current working directory of the executable at runtime.
            vShaderFile.open(path + vertexPath);
            fShaderFile.open(path + fragmentPath);
            std::stringstream vShaderStream, fShaderStream;
            vShaderStream << vShaderFile.rdbuf();
            fShaderStream << fShaderFile.rdbuf();
            vShaderFile.close();
            fShaderFile.close();
            vectorCode = vShaderStream.str();
            fragmentCode = fShaderStream.str();
            std::cout << "Shader files read successfully" << std::endl;
            std::cout << vectorCode << std::endl;
            std::cout << fragmentCode << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cout << "ERROR::SHADER::FILE_NOT_SUCCESSFULLY_READ" << std::endl;
        }
        const char *vShaderCode = vectorCode.c_str();
        const char *fShaderCode = fragmentCode.c_str();
    }
};

#endif