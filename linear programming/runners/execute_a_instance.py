import sys
sys.path.append(r'/home/valdomiro/Programming/TCC/Algoritmos-TCC/linear programming')
from gurobi_optimization import optimization
instance_name = r'inst0'
opt = optimization()
opt.read_instance(name=instance_name)
opt.run_optimization(time_limit=3600.0)
print('valor ótimo encontrado: {valor_otimo}, gap: {gap}, runtime: {runtime}'.format(valor_otimo=opt.optimal_value,gap=opt.gap,runtime=opt.runtime))
