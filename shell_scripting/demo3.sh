#!/bin/bash

# -n -> no new line
# -e -> escape seq
echo -n -e "login Name: "
whoami

echo "Home Dir:"
pwd

echo "Current shell="
echo "$SHELL"

