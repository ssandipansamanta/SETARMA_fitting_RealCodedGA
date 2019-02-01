Fitting SETAR-SETARMA using RCGA
================================

# Introduction

In the class of Nonlinear time-series models, Self-exciting threshold autoregressive moving average model (SETARMA) may be employed to describe cyclical data having sudden rise and fall, i.e. the model is capable of exhibiting “limit cycle” behaviour. The estimation of parameters of SETARMA two-regime model requires simultaneously delay parameter, threshold parameter, the autoregressive (AR) and moving average (MA) orders and lags be determined according to Normalized Akaike Information Criterion (NAIC). This is combinatoric-like problem where the solution has to be searched in a discrete large space. Only if the problem size is smallest all possible models may be tried.

Therefore powerful stochastic optimization technique of genetic algorithm (GA) has been used for estimation of parameters of SETARMA model. GA is target-oriented parallel search technique and is mainly applied to optimization process searching for universal or nearly universal extreme values. From the view point of better search power, solving a real-valued optimization problem using real-coded GA (RCGA) which, applied on real solutions, is more efficient than transforming it into binary-coded GA.

***
# Future Work

* Fourier SETARMA estimation using RCGA.

# Reference
* Samanta Sandipan, Prajneshu and Ghosh, Himadri (2011). Modelling and forecasting cyclical fish landings: SETARMA nonlinear time-series approach, *Indian Journal of Fisheries*, **58(3)**: 39 - 43.
* Ghosh Himadri, Prajneshu and Samanta Sandipan (2013). Fitting of SETARMA nonlinear time-series model through Genetic algorithm and development of out-of-sample forecasts *Statistics: A Journal of Theoretical & Applied Statistics*. **48(5)**: 1166-1184.