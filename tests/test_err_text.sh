#!/bin/bash

for file in files_cub/err_text/*.cub
do
    echo "Running: $file"
    cat $file
    echo
    ./cub3D "$file"
    echo "----------------------"
done
