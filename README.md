# 📘 Project Setup Guide (Ubuntu)

## 🖥️ System Requirements

* Ubuntu (fresh install)
* Python 3.8 → 3.12 supported
* Internet connection

---

## 🚀 1. Update System

```bash
sudo apt update && sudo apt upgrade -y
```

---

## 🐍 2. Install Python & Tools

### Default Python (recommended)

```bash
sudo apt install python3 python3-pip python3-venv python3-dev -y
```

### (Optional) Install specific version

```bash
sudo apt install python3.12 python3.12-venv python3.12-dev -y
```

---

## 📦 3. Create Virtual Environment (IMPORTANT)

```bash
python3 -m venv myenv
source myenv/bin/activate
```

---

## ⚙️ 4. Install Build Dependencies (VERY IMPORTANT)

These fix most pip install failures:

```bash
sudo apt install build-essential libatlas-base-dev libjpeg-dev zlib1g-dev -y
```

---

## 🔧 5. Fix pip, wheel & setuptools (CRITICAL STEP)

### ❗ Problem

Many installations fail because:

* wheel is missing
* setuptools is outdated
* pip cannot build packages

### ✅ Solution

Always upgrade before installing requirements:

```bash
pip install --upgrade pip setuptools wheel
```

---

## 📥 6. Install Project Requirements

```bash
pip install -r requirements.txt
```

---

## ⚠️ Common pip / wheel Issues

### ❌ Error: "Failed building wheel for numpy / pandas"

**Cause:** Missing compilers or wheel package

**Fix:**

```bash
pip install --upgrade pip setuptools wheel
sudo apt install build-essential
```

---

### ❌ Error: "No module named wheel"

**Fix:**

```bash
pip install wheel
```

---

### ❌ Error: "Python.h: No such file or directory"

**Fix:**

```bash
sudo apt install python3-dev
```

---

### ❌ Error: "gcc not found"

**Fix:**

```bash
sudo apt install build-essential
```

---

### ❌ Error: "Could not build wheels for X"

**Fix:**

```bash
pip install --only-binary :all: numpy pandas
```

---

### ❌ Error: Old pip version

**Fix:**

```bash
pip install --upgrade pip
```

---

## 📊 7. Jupyter Notebook Setup

```bash
pip install notebook
jupyter notebook
```

---

## ⚠️ Important Notes

### 🔹 `%matplotlib inline`

* Works only in Jupyter Notebook
* Remove if running `.py` file

---

### 🔹 Permissions issue

If you see:

```
Permission denied
```

Use:

```bash
pip install --user -r requirements.txt
```

OR use virtual environment (recommended)

---

### 🔹 Display issues (matplotlib)

If plots don’t show:

```bash
sudo apt install python3-tk
```

---

## 🧪 8. Verify Installation

Run:

```python
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
from sklearn.preprocessing import MinMaxScaler
```

If no errors → setup is correct ✅

---

## 🧠 Pro Tips

* Always use virtual environments
* Always upgrade pip + wheel before installing packages
* Prefer prebuilt wheels (faster, fewer errors)

---

## 🚀 One-Command Setup (Recommended)

```bash
sudo apt update && \
sudo apt install python3-pip python3-venv python3-dev build-essential libatlas-base-dev python3-tk -y && \
python3 -m venv myenv && \
source myenv/bin/activate && \
pip install --upgrade pip setuptools wheel && \
pip install -r requirements.txt
```

---

## ✅ Done!

Your environment is now ready to run the notebook 🎉
