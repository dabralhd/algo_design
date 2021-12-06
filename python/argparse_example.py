import argparse

parser = argparse.ArgumentParser()
parser.add_argument('number', help="number whose cube is required", type=int)
args = parser.parse_args()

print(args.number**3) 
x =   2
