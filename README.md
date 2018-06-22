# Schedules

The goal of this project is to write a program that generates schedules with a genetic algorithm.


## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.

### Prerequisites

- [easea](http://easea.unistra.fr/index.php/EASEA_platform) : An Artificial Evolution platform that allows to implement evolutionary algorithms and to exploit the massive parallelism of many-core architectures.

### compilation

Generate the project by using easea : `./easea schedules.ez`.

Apply the patch : `./hack.sh`.

Compile using the makefile : `make`.

```
- clear : Clean previous compilation.
```

### use

Start the program  : `./schedules`.

## Authors

* **MANCIAUX Romain** - *Initial work* - [PamplemousseMR](https://github.com/PamplemousseMR).
* **HANSER Florian** - *Initial work* - [ResnaHF](https://github.com/ResnaHF).

## License

This project is licensed under the GNU Lesser General Public License v3.0 - see the [LICENSE.md](LICENSE.md) file for details.