.PHONY: clean All

All:
	@echo "----------Building project:[ Main - Debug ]----------"
	@cd "Main" && "$(MAKE)" -f  "Main.mk"
clean:
	@echo "----------Cleaning project:[ Main - Debug ]----------"
	@cd "Main" && "$(MAKE)" -f  "Main.mk" clean
