# Makefile

# Target to clean the repository
clean:
	@echo "Cleaning repository..."
	# Remove files with 'bin' extension
	find . -type f -name '*bin' -exec rm -f {} +
	# Remove files with 'dSYM' extension
	find . -type f -name '*dSYM' -exec rm -f {} +
	# Remove directories ending with '.bin.dSYM'
	find . -type d -name '*.bin.dSYM' -exec rm -rf {} +
	# Remove all .cph folders
	find . -type d -name "*.cph" -exec rm -rf {} \;
	# Remove all .vscode folders
	find . -type d -name "*.vscode" -exec rm -rf {} \;

# Optional: Add a phony target to avoid conflicts with files named 'clean'
.PHONY: clean
