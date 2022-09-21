#!/usr/bin/bash

version=$(git rev-parse --short HEAD)
dirty=$([[ -n $(git status -s) ]] && echo '-dirty')
echo $version$dirty
