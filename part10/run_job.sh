#!/bin/sh
#PBS -l nodes=2:ppn=4
#PBS -l walltime=72:00:00
#PBS -q imos
#PBS -N exc10

 echo "================================================================"
 echo "PBS_JOBID=$PBS_JOBID"
 echo "PBS_JOBNAME=$PBS_JOBNAME"
 echo "PBS_O_HOST=$PBS_O_HOST"
 echo "PBS_O_QUEUE=$PBS_O_QUEUE"
 echo "PBS_O_WORKDIR=$PBS_O_WORKDIR"
 echo "----------------------------------------------------------------"
  cat $PBS_NODEFILE
 echo "================================================================"

 set -vx

# detect number of CPUs
 NCPU=`cat ${PBS_NODEFILE} | wc -l`

# location of executable and pseudopotentials
 EXE=~imostest/DynSim/part10/cpmd.x_2017
 PP=###FIXME###

# working directory
 WDIR=###FIXME###

# Time for the job (check #PBS entry!)
 RUNTIME=72
 TIME_TO_SLEEP=$(($RUNTIME*3600-600))

# run job in local SCRATCH area
 SCR=/SCRATCH/${USER}_${PBS_JOBID}
 mkdir ${SCR}
 cd ${SCR}

# import job data 
 cp -p ${WDIR}/* ${SCR}

# run the job
 (sleep ${TIME_TO_SLEEP}; touch EXIT) &
 module purge
 #module add mpi/openmpi-x86_64 #does not work anymore include hardcoded openmpi below
 module add ifort
 module list
 export PATH=/home/imostest/DynSim/bin:${PATH} 
 export LD_LIBRARY_PATH=/home/imostest/DynSim/lib:${LD_LIBRARY_PATH}
 mpirun --mca btl_tcp_if_exclude 127.0.0.1/8,virbr0 --prefix /home/imostest/DynSim -x LD_LIBRARY_PATH -machinefile ${PBS_NODEFILE} -v -np ${NCPU} ${EXE} ./cpmd.in ${PP} > ./cpmd.out 2> ./cpmd.err

# export job data 
 cp -p ./* ${WDIR}
 cd - 

 rm -rf ${SCR}

# exit without error
 exit 0


