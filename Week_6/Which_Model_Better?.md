![[Pasted image 20240925174619.png]]
## Execution Time 
- Regarding execution time, the boss/workers model took 360ms to complete 11 toy orders with 6 workers,
- while the pipeline model took 320ms with the same constraints.
- From the perspective of total execution time, the pipeline model performs better than the boss/workers model.

## AVG time 
1. Boss-worker
- For the boss/workers problem, the first five orders took 120ms to complete. The second five orders had to wait 120ms and then took 120ms to complete. The final order had to wait 240ms and then took 120ms to complete. Thus the average time per order was: 
```
otal_orders = 11
total_time = (120 * 5) + (2 * 120 * 5) + (3 * 120)

average_time_per_order =  total_time / total_orders=196 
```
2. PIpeline 
- For the pipeline model, the first order took 120ms to complete. 
- The second order waited 20ms for the first order to leave the first stage, and then took 120ms to complete. The third order waited 20ms on the first order, and 20ms on the second order, and then took 120ms to complete. Thus, the average time per order is: 
```
total_orders = 11
total_time =
	 sum += 120  + (20 * order)
end

average_time_per_order =  total_time / total_orders= 220 ms
```

If execution time is important, pick the pipeline model. Rather, if we care about the average time to complete the order, the boss/workers model is better.

It's usually not possible to decree that one model is better than the other. Performance of a model is relative to the metric being measured, and different metrics may be important in different contexts.
