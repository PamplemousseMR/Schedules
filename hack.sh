#!/bin/sh
#Script de gros hack
sed -i -e "s/int \*m_schedules/void \*m_schedules/g" schedulesIndividual.hpp
sed -i -e "s/if (m_schedules) delete m_schedules/Schedules\* me = (Schedules\*)m_schedules;\n  if (me) delete me/g" schedulesIndividual.cpp
sed -i -e "s/m_schedules=(genome.m_schedules ? new int(\*(genome.m_schedules)) : NULL)/m_schedules=(void\*)(genome.m_schedules ? new Schedules(\*((Schedules\*)genome.m_schedules)) : NULL)/g" schedulesIndividual.cpp