#!/bin/bash

for file in files_cub/err_map/*.cub
do
    echo "Running: $file"
    cat $file
    echo
    ./cub3D "$file"
    echo "----------------------"
done
