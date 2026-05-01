from enum import IntEnum

class Precision(IntEnum):
    FOUR = 4
    EIGHT = 8

def create_eps_script(
        layers: int = 10,
        precision: Precision = Precision.EIGHT,
        timestep: int = 45,
        run_steps: int = 11520,
        nstpw: int = 160,
        flux: float = 1367.,
        star_temp: float = 5780.,
        year: float = 360.,
        eccentricity: float = 0.016715,
        fixed_orbit: bool = True,
        rotation_period: float = 1.,
        obliquity: float = 23.441,
        lon_vernal_eq: float = 102.7,
        synchronous: bool = False,
        substellar_lon: float = 180.,
        desync: float = 0.,
        tlcontrast: float = 0.,
        gravity: float = 9.80665,
        radius: float = 1.,
        pN2: float = 0.7809,
        pO2: float = 0.2095,
        pAr: float = 0.0093,
        pCO2: float = 300e-6,
        ozone: bool = True,
        pH2: float = 0.,
        pHe: float = 0.,
        pNe: float = 0.,
        pKr: float = 0.,
        pH2O: float = 0.,
        wet_soil: bool = True,
        vegetation: int = 2,
        vegaccel: int = 1,
        init_growth: float = 0.5,
        glaciers: bool = True,
        glac_min_depth: float = 2.,
        glac_init_height: float = -1.,
        out_file: str = "eps_run.py"
        ):
    script = f"""import exoplasim as exo
model = exo.Model(workdir='run',modelname='model',outputtype='.nc',
    layers={layers},ncpus=8,precision={precision},crashtolerant=True)

model.configure(timestep={timestep},runsteps={run_steps},otherargs={{'NSTPW@plasim_namelist':'{nstpw}'}},
    physicsfilter='gp|exp|sp',
    flux={flux},startemp={star_temp},
    year={year},eccentricity={eccentricity},fixedorbit={fixed_orbit},
    rotationperiod={rotation_period},obliquity={obliquity},lonvernaleq={lon_vernal_eq},
    synchronous={synchronous},substellarlon={substellar_lon},desync={desync},tlcontrast={tlcontrast},
    gravity={gravity},radius={radius},
    landmap='maps/land.sra',topomap='maps/topo.sra',
    pN2={pN2},pO2={pO2},pAr={pAr},pCO2={pCO2},ozone={ozone},
    pH2={pH2},pHe={pHe},pNe={pNe},pKr={pKr},pH2O={pH2O},
    wetsoil={wet_soil},vegetation={vegetation},vegaccel={vegaccel},initgrowth={init_growth},
    glaciers={{'toggle':{glaciers},'mindepth':{glac_min_depth},'initialh':{glac_init_height}}})

model.cfgpostprocessor(times=12,extension='.nc')

model.exportcfg()

model.runtobalance(baseline=10,maxyears=300,minyears=20,timelimit=480,clean=True)

model.run(years=10)

model.finalize('model_out',allyears=True,clean=True,keeprestarts=True)

model.save()
"""
    with open(out_file, 'w') as f:
        f.write(script)

if __name__ == "__main__":
    create_eps_script()
