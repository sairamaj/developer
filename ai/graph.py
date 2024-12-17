import matplotlib.pyplot as plt

# Sample data
x = [1, 2, 3, 4, 5]
y = [2, 3, 5, 7, 11]

# Create a line plot
plt.plot(x, y, marker='o')

# Add a title and labels
plt.title("Sample Line Graph")
plt.xlabel("X-axis")
plt.ylabel("Y-axis")

# Show the plot
plt.show()
