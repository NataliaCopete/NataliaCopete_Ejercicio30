!/bin/bash
#PBS -l nodes=1:intel:ppn=1, mem=64gb
#PBS -l walltime=00:15:00
#PBS -M n.copete@uniandes.edu.co
#PBS -m abe
#PBS -N ncpexo30
#PBS -j oe

module load anaconda/python3
cd $PBS_O_WORKDIR
export OMP_NUM_THREADS=5
g++ -fopenmp -o burgers_para_x burgers_para.c
./burgers_para_x>advecc_para.txt
c++ -o burgers_ser_x burgers_ser.c
./burgers_ser_x>advecc_ser.txt
python graf_ad.py

