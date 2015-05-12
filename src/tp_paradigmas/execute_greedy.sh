#!/bin/bash
EXE_NAME="tp_paradigmas"
readonly EXE_NAME
BIN_DIR="./bin"
INPUTS_DIR="./inputs"
readonly INPUTS_DIR
OUTPUTS_DIR="./outputs"
readonly OUTPUTS_DIR
PARADIGM="greedy"
readonly PARADIGM
echo "Executando o algoritmo guloso"
$BIN_DIR/$EXE_NAME -i $INPUTS_DIR/inputs.txt -o $OUTPUTS_DIR/outputs.txt -p $PARADIGM