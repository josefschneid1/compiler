FROM ubuntu:22.04

WORKDIR /src

RUN apt-get update && apt-get install gcc python3 python3-pip -y && python3 -m pip install conan

