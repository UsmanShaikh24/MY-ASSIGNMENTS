# EV Powertrain & Battery System Models

This repository provides an extensive suite of MATLAB Simulink models that simulate both Electric Vehicle (EV) and Conventional Internal Combustion Engine (ICE) powertrains, as well as a modular and scalable battery pack system. These models are tailored for engineering students, researchers, and professionals aiming to analyze and develop efficient vehicular energy systems.

Designed with educational and simulation goals in mind, the models offer a practical way to study key concepts such as regenerative braking, electric drive systems, energy storage mechanisms, and battery discharge behavior.

---

## 📦 Contents

| File/Folder | Description |
|-------------|-------------|
| `EVPowertrain.slx` | Simulink model simulating an electric vehicle powertrain, including the electric motor, power electronics, vehicle body, and control logic. Useful for studying acceleration, regenerative braking, and energy consumption. |
| `Convectional_Powertrain.slx` | Simulates a conventional vehicle with an internal combustion engine, transmission system, and drivetrain. Can be used to compare performance and efficiency with EV systems. |
| `DISCHARGE CIRCUIT.mdl` | A specialized model for simulating the discharge behavior of battery cells or packs under load. Helps analyze voltage drops, current profiles, and thermal effects. |
| `Battery Pack/` | Directory containing a full-featured, modular battery system including Simscape-based components, configuration data, and supporting files. |
| └── `Batteries.slx` | Main simulation model for the battery pack with detailed cell, module, and pack configurations. |
| └── `Batteries_lib.slx` | Custom library file containing reusable Simulink blocks for battery simulation (modules, thermal systems, etc.). |
| └── `Batteries.mat` | Initialization and configuration parameters for battery types, voltages, capacities, and thermal properties. |
| └── `+Batteries/Modules` | Simscape files defining individual battery modules with type specifications and visual representations. |
| └── `+Batteries/ParallelAssemblies` | Contains definitions for parallel assembly configurations and custom SVG representations for visualization. |

---

## 🚗 Features

- ✅ **Dual Powertrain Modeling**: Supports both electric and conventional vehicle architectures.
- ⚙️ **Battery Pack Simulation**: Includes individual cell behavior, thermal models, and parallel-series configurations.
- 🔄 **Regenerative Braking**: Demonstrates how electric vehicles recover energy during braking.
- 🧩 **Reusable Libraries**: Custom Simulink blocks for rapid modeling and development.
- 📊 **Discharge Circuit Analysis**: Monitor battery performance and simulate degradation or load-specific effects.

---

## 🧪 Requirements

To run the simulations effectively, ensure the following software and toolboxes are installed:

- MATLAB R2022a or later
- Simulink
- Simscape
- Simscape Electrical
- Simscape Battery (highly recommended for battery models)

---

## 🚀 Getting Started

1. **Clone this repository**
   ```bash
   git clone https://github.com/your-username/ev-powertrain-models.git
   ```
2. **Open MATLAB** and navigate to the cloned folder.
3. **Run a model**:
   - Double-click any `.slx` or `.mdl` file (e.g., `EVPowertrain.slx`).
   - Simulink will open the graphical environment where you can simulate and explore each block.
4. **Customize Configurations**:
   - Modify `Batteries.mat` to simulate different battery specifications.
   - Use or extend `Batteries_lib.slx` to integrate new component models.

---

## 📜 License

This repository is intended for academic and research purposes. You may use, modify, and share it freely with proper attribution. Commercial use requires prior permission.

---

## 🙌 Acknowledgments

This work integrates components developed using MATLAB's Simscape and Simulink environment. Special thanks to the Simscape Battery Toolbox for enabling accurate modeling of electrochemical systems.

---

Feel free to contribute or raise issues to improve these models. Happy simulating!

