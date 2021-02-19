.PHONY: clean All

All:
	@echo "----------Building project:[ Utilidades - Debug ]----------"
	@cd "Utilidades" && "$(MAKE)" -f  "Utilidades.mk"
clean:
	@echo "----------Cleaning project:[ Utilidades - Debug ]----------"
	@cd "Utilidades" && "$(MAKE)" -f  "Utilidades.mk" clean
