
device = torch.device('cuda' if torch.cuda.is_available() else 'mps' if torch.backends.mps.is_available() else 'cpu')
display(device)

RANDOM_SEED = 13
np.random.seed(RANDOM_SEED)
torch.manual_seed(RANDOM_SEED)

# Syntetic Data Generation
true_b = 1
true_w = 2
N = 200

x = np.random.rand(N, 1)
epsilon = (0.1 * np.random.randn(N, 1))
y = true_b + true_w * x + epsilon

x_tensor = torch.as_tensor(x).float()
y_tensor = torch.as_tensor(y).float()
# All data points
dataset = TensorDataset(x_tensor, y_tensor)

# Generates train and validation sets
ratio = 0.8
n_total = len(dataset)
n_train = int(n_total * ratio)
n_validation = n_total - n_train
train_data, validation_data = random_split(dataset, [n_train, n_validation])
display(train_data[:5])

# Data Loaders
train_loader = DataLoader(dataset=train_data, batch_size=16, shuffle=True)
validation_loader = DataLoader(dataset=validation_data, batch_size=16)

# Extract train and validation data
x_train, y_train = zip(*[(x, y) for x, y in train_data])
x_val, y_val = zip(*[(x, y) for x, y in validation_data])

# Convert to numpy arrays for plotting
x_train = np.array(x_train)
y_train = np.array(y_train)
x_val = np.array(x_val)
y_val = np.array(y_val)

# Plotting
plt.scatter(x_train, y_train, color='blue', s=5, label='Train Data')
plt.scatter(x_val, y_val, color='red', s=5, label='Validation Data')
plt.legend()
plt.title('Training and Validation Data')
plt.xlabel('x')
plt.ylabel('y')
plt.show()

x_train_tensor = torch.as_tensor(x_train, dtype=torch.float32, device=device)
y_train_tensor = torch.as_tensor(y_train, dtype=torch.float32, device=device)
