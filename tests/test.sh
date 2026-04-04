#!/bin/bash

for file in files_cub/*.cub
do
    echo "Running: $file"
    ./cub3D "$file"
    echo "----------------------"
done
