#!/bin/sh
#SBATCH -J imosCPMD
#SBATCH --exclusive
#SBATCH -N 2
#SBATCH -p imos_A
#SBATCH --ntasks=8
#SBATCH --ntasks-per-node=4
#SBATCH --time=72:00:00
#SBATCH --account=imos2023
#SBATCH --exclude=imospc15

 echo "================================================================"
 echo "SLURM_JOBID=$SLURM_JOBID"
 echo "SLURM_JOB_NAME=$SLURM_JOB_NAME"
 echo "SLURMD_NODENAME=$SLURMD_NODENAME"
 echo "SLURM_JOB_PARTITION=$SLURM_JOB_PARTITION"
 echo "----------------------------------------------------------------"
 echo $SLURM_JOB_NODELIST
 echo "================================================================"

 set -vx

# location of executable and pseudopotentials
 EXE=/home/imostest/DynSim/part9/cpmd.x
 PP=/home/imostest/DynSim/part9

# working directory
 WDIR=###FIXME###

# Time for the job (check #SBATCH entry!)
 RUNTIME=72
 TIME_TO_SLEEP=$(($RUNTIME*3600-600))

# run job in local SCRATCH area
 SCR=/SCRATCH/${USER}_${SLURM_JOBID}
 mkdir ${SCR}
 cd ${SCR}

# import job data 
 cp -p ${WDIR}/* ${SCR}

# run the job
 (sleep ${TIME_TO_SLEEP}; touch EXIT) &
 module purge
 module add ifort/2015.2 icc/2015.2 openmpi-intel/1.10.2-intel-2015.2.164
 module list
 mpirun --mca btl_tcp_if_exclude 127.0.0.1/8,virbr0 -x LD_LIBRARY_PATH -v ${EXE} ./cpmd.in ${PP} > ./cpmd.out 2> ./cpmd.err

# export job data 
 cp -p ./* ${WDIR}
 cd - 

 rm -rf ${SCR}

# exit without error
 exit 0

