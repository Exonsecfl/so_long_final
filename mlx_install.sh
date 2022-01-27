#!/bin/sh

echo "-----------------------------------"
echo "MLX installation into mlx subfolder"
echo "-----------------------------------"

rm -rv mlx
tar -xzvf minilibx_opengl.tgz
mv minilibx_opengl_20191021 mlx
cd ./mlx
make
cd ..
make all
