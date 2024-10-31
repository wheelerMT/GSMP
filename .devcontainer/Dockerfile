FROM ubuntu:24.10

# Install additional packages
RUN apt-get update \
    && apt-get -y upgrade \
    && apt-get -y install \
        clang \
        clangd \
        cmake \
        git \
    && apt-get clean

# Ensure workspace is allowed by git
# RUN git config --global --add safe.directory /workspaces/GSMP