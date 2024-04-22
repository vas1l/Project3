import matplotlib.pyplot as plt

def read_data(filepath):
    temperature_data = {}
    country_name = "Country"

    with open(filepath, 'r') as file:
        lines = file.readlines()
        start_recording = False

        for line in lines:
            line = line.strip()
            if line.startswith("Country:"):
                country_name = line.split(':')[1]

            if line.startswith("Temperature Change:"):
                start_recording = True
                continue
            
            if start_recording:
                if line:
                    parts = line.split(': ')
                    if len(parts) == 2:
                        year = parts[0].strip()
                        temp_change = float(parts[1].strip())
                        temperature_data[int(year)] = temp_change
                else:

                    break

    return country_name, temperature_data

def plot_temperature_changes(country_name, temperature_data):
    years = list(temperature_data.keys())
    temperatures = list(temperature_data.values())

    plt.figure(figsize=(10, 5))
    plt.plot(years, temperatures, marker='o', linestyle='-', color='b')
    plt.title(f"Temperature Change Over Years in {country_name}")
    plt.xlabel("Year")
    plt.ylabel("Temperature Change (°C)")
    plt.grid(True)
    plt.show()

file_path = 'country_data.txt'

country_name, temperature_data = read_data(file_path)
plot_temperature_changes(country_name, temperature_data)