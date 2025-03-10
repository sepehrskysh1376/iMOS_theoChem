#!/bin/bash
temperature=${1}
filebase=run_${1}
sed "s/@REFTEMP@/${temperature}/" template.mdp > ${filebase}.mdp
echo "Grompping now (log file in ${filebase}.grompp_log"
source /home/imostest/gromacs/bin/GMXRC
gmx grompp -f ${filebase}.mdp -c water_nvt.gro -p water.top -o ${filebase}.tpr &> ${filebase}.grompp_log
echo "Running MD (log file in ${filebase}.mdrun_log)"
gmx mdrun -v -deffnm ${filebase} &> ${filebase}.mdrun_log
echo "Getting energy and estimate error"
gmx energy -f ${filebase}.edr -s ${filebase}.tpr -b 10 > ${filebase}.energy_out 2> ${filebase}.energy_err << EOF
7
EOF
echo -n "${temperature} " >> water_energies.dat 
awk '/Total Energy/ {print $3,$4}' ${filebase}.energy_out >> water_energies.dat 
