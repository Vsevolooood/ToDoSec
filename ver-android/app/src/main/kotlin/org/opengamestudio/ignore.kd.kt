package org.opengamestudio



data class MainContext(
    var didClickSaveText: Boolean = false,
    var didLaunch: Boolean = false,
    var didSelectTask: String = "",
    var didSetup: Boolean = false,
    var isVisible: Boolean = false,
    var saveString: String = "",
    var shouldSavaTasks: Boolean = false,
    var taskTitle: String = "",
    var tasks: Array<String> = arrayOf(),
    override var recentField: String = "",
): KDContext {
    override fun <T> field(name: String): T {
        if (name == "didClickSaveText") {
            return didClickSaveText as T
        } else if (name == "didLaunch") {
            return didLaunch as T
        } else if (name == "didSelectTask") {
            return didSelectTask as T
        } else if (name == "didSetup") {
            return didSetup as T
        } else if (name == "isVisible") {
            return isVisible as T
        } else if (name == "saveString") {
            return saveString as T
        } else if (name == "shouldSavaTasks") {
            return shouldSavaTasks as T
        } else if (name == "taskTitle") {
            return taskTitle as T
        } else if (name == "tasks") {
            return tasks as T
        }
        return "unknown-field-name" as T
    }

    override fun selfCopy(): KDContext {
        return this.copy()
    }

    override fun setField(
        name: String,
        value: Any?
    ) {
        if (name == "didClickSaveText") {
            didClickSaveText = value as Boolean
        } else if (name == "didLaunch") {
            didLaunch = value as Boolean
        } else if (name == "didSelectTask") {
            didSelectTask = value as String
        } else if (name == "didSetup") {
            didSetup = value as Boolean
        } else if (name == "isVisible") {
            isVisible = value as Boolean
        } else if (name == "saveString") {
            saveString = value as String
        } else if (name == "shouldSavaTasks") {
            shouldSavaTasks = value as Boolean
        } else if (name == "taskTitle") {
            taskTitle = value as String
        } else if (name == "tasks") {
            tasks = value as Array<String>
        }
    }
}
/**
 * This file is a part of Kotlin dialect:
 *     https://github.com/OGStudio/kotlin-dialect
 * License: CC0
 * Version: 3.1.0
 */






interface KDContext {
    /**
     * Name of the field that has just been changed
     *
     * Allows should-functions (reducers) to react only to
     * relevant changes and ignore other changes of KDContext
     */
    var recentField: String

    /**
     * Get field's value by its name
     */
    fun <T> field(name: String): T
    /**
     * Erase type
     *
     * Used by KDController to assign recent field's value
     */
    fun fieldAny(name: String): Any {
        return field(name)
    }
    /**
     * Create a copy of the KDContext derivative
     *
     * Used by KDController to treat all derived contexts as KDContext
     */
    fun selfCopy(): KDContext
    /**
     * Set field's value by its name
     */
    fun setField(name: String, value: Any?)
}
/**
 * This file is a part of Kotlin dialect:
 *     https://github.com/OGStudio/kotlin-dialect
 * License: CC0
 * Version: 3.1.0
 */





val KD_FIELD_NONE = "none"


class KDController(
    var context: KDContext
) {
    internal var callbacks = mutableListOf<(c: KDContext) -> Unit>()
    internal var functions = mutableListOf<(c: KDContext) -> KDContext>()
    var isProcessingQueue = false
    internal var queue = mutableListOf<KDContext>()
 
    fun executeFunctions() {
        val c = queue.removeAt(0)
        context.recentField = c.recentField
        context.setField(c.recentField, c.fieldAny(c.recentField))
       
        for (f in functions) {
            val ctx = f(context.selfCopy())
            if (ctx.recentField != KD_FIELD_NONE) {
                queue.add(ctx)
            }
        }
       
        reportContext()
    }
 
    fun processQueue() {
        // Prevent recursion.
        if (isProcessingQueue) {
            return
        }
       
        isProcessingQueue = true
       
        while (queue.size > 0) {
            executeFunctions()
        }
       
        isProcessingQueue = false
    }
 
    fun registerCallback(cb: (c: KDContext) -> Unit) {
        callbacks.add(cb)
    }
 
    fun registerFieldCallback(
        fieldName: String,
        cb: (KDContext) -> Unit
    ) {
        callbacks.add({ c ->
            if (c.recentField == fieldName) {
                cb(c)
            }
        })
    }
 
    fun registerFunction(f: (KDContext) -> KDContext) {
        functions.add(f)
    }
 
    fun reportContext() {
        for (cb in callbacks) {
            cb(context)
        }
    }
 
    fun set(fieldName: String, value: Any) {
        var c = context.selfCopy()
        c.setField(fieldName, value)
        c.recentField = fieldName
        queue.add(c)
        processQueue()
    }
}
/**
 * This file is a part of Kotlin dialect:
 *     https://github.com/OGStudio/kotlin-dialect
 * License: CC0
 * Version: 3.1.0
 */





// Register several oneliner callbacks to a controller

fun registerOneliners(
    ctrl: KDController,
    items: Array<Any>
) {
    val halfCount = items.size / 2
    for (i in 0..<halfCount) {
        val field = items[i * 2] as String
        val callback = items[i * 2 + 1] as (c: KDContext) -> Unit
        ctrl.registerFieldCallback(field, callback);
    }
}

// Special object to reference context fields with a compile time validation

object F {
    const val didClickSaveText = "didClickSaveText"
    const val didLaunch = "didLaunch"
    const val didSelectTask = "didSelectTask"
    const val didSetup = "didSetup"
    const val isVisible = "isVisible"
    const val none = "none"
    const val saveString = "saveString"
    const val shouldSavaTasks = "shouldSavaTasks"
    const val taskTitle = "taskTitle"
    const val tasks = "tasks"

}
