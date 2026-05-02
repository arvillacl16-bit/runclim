import epspost
import sys

epspost.image_to_dem("topo.png", "topo.nc", float(sys.argv[1]))
epspost.correct_temp("raw.nc", "final.nc", "topo.nc", g=float(sys.argv[2]))
epspost.correct_precipitation("final.nc", "final.nc", "topo.nc")
