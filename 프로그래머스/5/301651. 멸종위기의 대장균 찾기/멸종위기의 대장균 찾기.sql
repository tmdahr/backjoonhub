with recursive tree as (
    select 
        ID,
        1 as GENERATION
    from ECOLI_DATA
    where parent_id is null
    
    union all

    select e.id, p.GENERATION+1 as GENERATION
    from ECOLI_DATA e
    join tree p
        on p.id = e.parent_id
)
select 
    count(ID) as COUNT,
    GENERATION
from tree
where id not in (
    select parent_id
    from ECOLI_DATA 
    where parent_id is not null
)
group by GENERATION
order by GENERATION;